Get-ChildItem -Path .\docs\latex\* -Recurse | Where-Object { $_.Name -ne '.gitkeep' } | Remove-Item -Force
Get-ChildItem -Path .\docs\html\*\* -Recurse | Where-Object { $_.Name -ne '.gitkeep' } | Remove-Item -Force
