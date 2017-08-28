set shell = CreateObject("WScript.Shell"):
shell.Run """C:\Programme\Immunity Inc\Immunity Debugger\ImmunityDebugger.exe"" ""C:\Dokumente und Einstellungen\codemeetup\Desktop\Tools\vulnserver\vulnserver.exe""":
WScript.Sleep 2000:
shell.AppActivate("Immunity Debugger"):
' Command Reference: https://github.com/kbandla/ImmunityDebugger/blob/master/1.73/Tools/cmdcli.py
shell.SendKeys "%{F1}", True: ' Alt + F1 -> Go to CmdLine
shell.SendKeys "RUN{Enter}", True: 'Continue process