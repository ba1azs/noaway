Add-Type @"
using System;
using System.Runtime.InteropServices;

public class IdleTime {
    [StructLayout(LayoutKind.Sequential)]
    struct LASTINPUTINFO {
        public uint cbSize;
        public uint dwTime;
    }

    [DllImport("user32.dll")]
    static extern bool GetLastInputInfo(ref LASTINPUTINFO plii);

    public static uint GetIdleTime() {
        LASTINPUTINFO lii = new LASTINPUTINFO();
        lii.cbSize = (uint)Marshal.SizeOf(lii);
        GetLastInputInfo(ref lii);
        return ((uint)Environment.TickCount - lii.dwTime);
    }
}
"@

Add-Type -AssemblyName System.Windows.Forms

$idleThreshold = 180000  # 3 minutes in milliseconds

while ($true) {
    Start-Sleep -Seconds 5

    $idleTime = [IdleTime]::GetIdleTime()

    if ($idleTime -ge $idleThreshold) {
        [System.Windows.Forms.SendKeys]::SendWait("{SCROLLLOCK}")
        Start-Sleep -Milliseconds 200
        [System.Windows.Forms.SendKeys]::SendWait("{SCROLLLOCK}")
    }
}
