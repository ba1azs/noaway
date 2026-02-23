Add-Type -AssemblyName System.Windows.Forms

while ($true) {
    Start-Sleep -Seconds 240
    [System.Windows.Forms.SendKeys]::SendWait("{SCROLLLOCK}")
    Start-Sleep -Milliseconds 200
    [System.Windows.Forms.SendKeys]::SendWait("{SCROLLLOCK}")
}