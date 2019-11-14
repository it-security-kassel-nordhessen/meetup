# Motivation
- Metasploit oft schwer zu verstehen, was passiert hinter den Kulissen

# Grundlegende Debug Komponenten

## Gem Pry

Allgemeine Debug-Grundlage.
Zum Erstellen von Code im Speicher.

## Gem Pry-Byebug

Zum Steppen im Debug-Modus

## Gem Pry-Doc

Zur Einsicht der Dokumentation von Methoden, Klassen usw.

# Demo

## Opfer-Beispiel

Referenzprojekt: [https://github.com/secf00tprint/payloadtester_lfi_rfi](https://github.com/secf00tprint/payloadtester_lfi_rfi)

Klonen und starten mit `./start_linux_network`

## Metasploit bauen und dem Netzwerk hinzufügen

Metasploit-Docker-Container erstellen und im Container zum Laufen bekommen: `README.md`

Setze das Kommado `binding.pry` in der Methode check in `modules/exploits/unix/webapp/php_include.rb`

Metasploit-Modul: 

`use exploit/unix/webapp/php_include`

Setze RHOST auf interne Docker-IP PHP angreifbarer Server (zB 172.18.0.4).
Setze RPORT auf Port PHP angreifbarer Server (80)
Setze PHPURI auf /lfi.php?page=XXpathXX

Eingabe von `check` und Metasploit springt in den Debugger Pry.

Aufruf von `help` um sich ein Bild der Kommandos zu machen.
