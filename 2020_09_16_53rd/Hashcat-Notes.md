# Kurzer Einblick in Hashcat
*Anmerkung:* Der Talk hatte keine Slides. In dieser Datei sind nur die Gedankenstützen.

Links:
- [Security-Meetup](https://www.meetup.com/de-DE/IT-Security-Kassel/events/272078845/)
- [offizielle Webseite](https://hashcat.net)
- [Hashcat auf GitHub](https://github.com/hashcat/hashcat)
- [Hashcat-Wiki](https://hashcat.net/wiki/)
- [Wortlisten](https://github.com/danielmiessler/SecLists)


## Was ist Hashcat?
- Hashcat ist ist ein Passwort-Cracker
	- Ähnlich zu [John The Ripper](https://www.openwall.com/john/)(JtR)
	- Ursprünglicher Autoren: "das Hashcat Team", u. A.:
		- Jens Steube (aka "atom")
		- Gabriele Gristina (aka "matrix")

- Fokus auf GPU-basiertes Cracking (im Vergleich zu JtR)
- Warum GPU?
	- GPU arbeitet "massivst parallel"
	- Das funktioniert aber nur gut, wenn man immer "das gleiche" machen muss
		- Jeder Thread macht die gleichen Operationen, nur auf anderen Daten. Alles im Gleichschritt.
		- Super für viele Hashing-Algorithmen (SHA, MD5, NTLM)
		- Es gibt Algorithmen, bei denen dieser Ansatz nicht so viel bringt

## Installation / Benutzung
- Runterladen auf GitHub oder der Seite [siehe Links oben]
- Ggf. notwenidige Treiber installieren (siehe Hinweise auf Webseite)
- Starten:
	- Windows und Linux sind im selben ZIP-Archiv, deshalb:
	- Linux: `./hashcat.bin --help`
	- Windows: `hashcat.exe --help`
- Wichtigste Swichtes:
	- Attack-Mode (`-a`)
		- `straigt`: Dictionary
        - `Brute Force` bzw. `Mask Attack`:
            - https://hashcat.net/wiki/doku.php?id=mask_attack
	- Hash-Type (`-m`)
	- Weiteres:
		- `-w`, `--workload-profile`
		- `-1`, `--custom-charset`

## Beispiel 0 - `example0.cmd`
- `example0.cmd` (.sh für Linux) zeigt ein Beispiel für MD5; `example0.hash` beinhaltet einen Haufen Hashes
- Hashcat speichert alle Hashes, die er jemals gebrochen hat, in einer "pot-File"
    - Wenn man einen Hash 2x sieht, wird er direkt daraus genommen
	- Standardmäßig ist es die `hashcat.potfile`


# Beispiel 1 - Zip-Datei
[Zip-Datei liegt im Repo des Security Meetups]

- Quelle für Wortliste: https://github.com/danielmiessler/SecLists
- `zip2john`, um einen Hash zu erstellen, den Hashcat lesen kann:
- Hashes-Übersichtsseite:
	- https://hashcat.net/wiki/doku.php?id=example_hashes
- rockyou alleine hat nicht geholfen
- Regeln!
	- Eine Regel macht aus einem einzigen Passwort ganz viele
	- So kann man Dictionary-Angriffe noch besser machen
	- Komplizierte Syntax, siehe https://hashcat.net/wiki/doku.php?id=rule_based_attack
	- Hashcat liefert selbst welche mit (`rules/best42.rule`)

# Beispiel 2 - Irgendein Hash
- Wenn man einen Hash vorliegen hat, den man nicht kennt: https://hashcat.net/wiki/doku.php?id=example_hashes

Challenge für die Zuhörer: `$P$BGWsS5zBvTiqc23tJh8eazu/yOcYXr.`

# Weiterführendes
- [OpenCL](https://de.wikipedia.org/wiki/OpenCL)
- [WPA2 mit Hashcat brechen](https://hashcat.net/wiki/doku.php?id=cracking_wpawpa2)
- [Benchmark auf 8 GTX 1080](https://gist.github.com/epixoip/a83d38f412b4737e99bbef804a270c40)
- [Hashtopolis](https://github.com/s3inlc/hashtopolis)
    - Hashcat-Wrapper für verteiltes Hashcat mit demselben Ziel
