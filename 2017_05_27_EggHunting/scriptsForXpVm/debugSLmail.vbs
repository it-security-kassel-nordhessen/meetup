set shell = CreateObject("WScript.Shell"):
shell.Run """C:\Programme\Immunity Inc\Immunity Debugger\ImmunityDebugger.exe"""
WScript.Sleep 2000:
shell.AppActivate("Immunity Debugger"):
' Command Reference: https://github.com/kbandla/ImmunityDebugger/blob/master/1.73/Tools/cmdcli.py
shell.SendKeys "^{F1}", True: ' Open Attach Window -> Strg + F1
shell.SendKeys "SLmail", True: ' Type Process Name
WScript.Sleep 500: 'wait for UI filter
shell.SendKeys "{Enter}", True: ' choose process
WScript.Sleep 2000: 'wait for Attaching Process
shell.SendKeys "%{F1}", True: ' Alt + F1 -> Go to CmdLine
shell.SendKeys "RUN{Enter}", True: 'Continue process