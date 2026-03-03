$exePath = "C:\tools\bin\ssmi.exe"
$progId  = "ssmi.msfile"

New-Item -Path "HKCU:\Software\Classes\.ms" -Force | Out-Null
Set-ItemProperty -Path "HKCU:\Software\Classes\.ms" -Name "(default)" -Value $progId

New-Item -Path "HKCU:\Software\Classes\$progId" -Force | Out-Null
Set-ItemProperty -Path "HKCU:\Software\Classes\$progId" -Name "(default)" -Value "MS File"

New-Item -Path "HKCU:\Software\Classes\$progId\DefaultIcon" -Force | Out-Null
Set-ItemProperty -Path "HKCU:\Software\Classes\$progId\DefaultIcon" -Name "(default)" -Value "`"$exePath`",0"

New-Item -Path "HKCU:\Software\Classes\$progId\shell\open\command" -Force | Out-Null
Set-ItemProperty -Path "HKCU:\Software\Classes\$progId\shell\open\command" -Name "(default)" -Value "`"$exePath`" `"%1`""

Write-Host "Association installed."
