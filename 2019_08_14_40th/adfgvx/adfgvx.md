---
author: Billy Duong
title: ADFGVX
revealjs-url: http://revealjs.com
theme: white
---

## Inhalt

Allgemein

Verfahren

Kryptoanalyse


# Allgemein

## Geschichtlicher Hintergrund

- ["Geheimschrift der Funker 1918"](https://de.wikipedia.org/wiki/ADFGX)

- manuelles Verschlüsselungsverfahren

- verwendet im 1. WK (Deutschland)

- entwickelt von [Fritz Nebel](https://de.wikipedia.org/wiki/Fritz_Nebel) (1891-1977)

- März 1918 *ADFGX*, Juni *ADFGVX*

- erstm. gebrochen von [Georges Painvin](https://en.wikipedia.org/wiki/Georges_Painvin) (1886-1980)

## Charakteristika

- Wahl "A, D, G, F, (V,) X"[\*](https://de.wikipedia.org/wiki/Morsezeichen) um Signalstörungen zu vermeiden

    ```
    A | · −
    D | − · ·
    G | − − ·
    F | · · − ·
    V | · · · −
    X | − · · −
    ```

- Verwendet Substitution und Transposition

- fraktionierendes Verfahren


# Verfahren

## Krytoverfahren 101

```
Alice        | UNSAFE COMMUNICATION TUNNEL |         Bob

m --E(k,m)-->           c                   --D(k,c)--> m

             | Eve                         |


---------------------------------------------------------
m : message
c : ciphertext
k : key
E : encryption function
D : decryption function
```

## Nachricht - m

- keine Leerzeichen, Buchstaben großgeschrieben

- Satzzeichen werden ersetzt (zB. X) oder ausgelassen

- Bei *ADFGX* muss ein Buchstabe gleich sein (zb. I = J)

- Bei *ADFGX* müssen Zahlen ausgeschrieben werden

- Beispiel:

    ```
    GEHEIMENACHRICHT
    ```

## Verschlüsselte Nachricht - c

- Besteht nur aus A, D, F, G, (V, ) X

- Wird in 5er Blöcken übertragen

- Beispiel:

    ```
    DFFAD GAADX DFFVV DVFDD DGGAD FDVDD AA
    ```

## Schlüssel - k

- 2 Wörter oder Zeichenketten (A-Z)

- 1\. Wort: 1-25 (ADFGX) bzw. 1-36 (ADFGVX)

- 2\. Wort: beliebig lang

- Beispiel:

    ```
    KRYPTOGRAPHIE, FLUSS
    ```

<br/>
<small>Anmerkung: Schlüssel wurde in Praxis einmal täglich gewechselt.</small>

## Verschlüsselung - E (I)

**1. Substitution über Polybios Quadrat**

```
 |A D F G V X        - 1. Wort als Schlüssel:
-·-----------          "KRYPTOGRAPHIE"
A|K R Y P T O
D|G A H I E B        - Dopplungen im Schlüssel werden
F|C D F J L M          ausgelassen: "KRYPTOGAHIE"
G|N Q S U V W
V|X Z 0 1 2 3        - Ersetzungstabelle bilden
X|4 5 6 7 8 9


m = G  E  H  E  I  M  E  N  A  C  H  R  I  C  H  T

 => DA DV DF DV DG FX DV GA DD FA DF AD DG FA DF AV
```

## Verschlüsselung - E (II)

**2. Spaltentransposition**

```
m' = DA DV DF DV DG FX DV GA DD FA DF AD DG FA DF AV

12534               12345   - in Spalten aufschreiben
-----               -----     (#Spalten = Länge 2. Wort)
DADVD           |   DAVDD
FDVDG           v   FDDGV   - Spalten nach 2. Wort
FXDVG     =>        FXVGD     anordnen FLUSS = 12534
ADDFA               ADFAD
DFADD               DFDDA   - Spalten von OBEN nach UNTEN
GFADF               GFDFA     ablesen (* ignorieren)
AV***               AV***

c = DFFADGAADXDFFVVDVFDDDGGADFDVDDAA
 => DFFAD GAADX DFFVV DVFDD DGGAD FDVDD AA
```

<br/>
<small>Alternativ: Statt * mit zB. X (VA) auffüllen.</small>

## Entschlüsselung - D

**1. Spaltentransposition**

```
12345               12534   - Spalten aufstellen (#Spalten 
-----               -----     = Länge 2. Wort)
DAVDD               DADVD
FDDGV               FDVDG   - * anhand von Länge setzen
FXVGD     =>        FXDVG
ADFAD               ADDFA   - Nachricht eintragen und Spalten
DFDDA               DFADD     nach 2. Wort anordnen
GFDFA               GFADF     
AV***               AV***   - Zeilen ablesen

 => DADVDFDVDGFXDVGADDFADFADDGFADFAV
```

**2. Substitution**

```
 => GEHEIMENACHRICHT
```


# Kryptoanalyse

## Werkzeuge (I)

**Transposition**

- zB. allgemeine Spaltentransposition
- Known Plaintext
- Bigramme + Trigramme
- Heuristische Verfahren

## Werzeuge (II)

**Monoalphabetische Substitution**

- zB. Cäsar-Chiffre
- Häufigkeitsanalyse

<br/>

**Koinzidenzindex [\*](https://de.wikipedia.org/wiki/Koinzidenzindex)**

$\displaystyle \mathbf {IC} ={\frac {\sum _{i=A}^{Z}n_{i}(n_{i}-1)}{N(N-1)}}$

## Probleme

- Häufigkeitsanalyse nicht direkt möglich

    - Transposition "zerreißt" die Doppelzeichen

- Heuristische Verfahren benötigen...

    - Nachbarschaftsfunktion
    - Kostenfunktion

- (Transpositions) Schlüssellänge ist sehr wichtig!

## Ansätze (I)

**SOLUTION OF THE ADFGVX SYSTEM [\*](https://www.nsa.gov/Portals/70/documents/news-features/declassified-documents/military-cryptanalysis/mil_crypt_IV.pdf)**

- "Special solution by means of identical endings" (98)

- "Special solution by means of identical beginnings" (105)

- "Special solution by the exact factor method" (123)

- "Basic principles of the general solution" (125)

## Ansätze (II)

**Heuristischer Ansatz [\*](https://www.tandfonline.com/doi/abs/10.1080/01611194.2016.1169461?journalCode=ucry20)**

- Transponieren und über **Koinzidenzindex** testen
    - $n_i$ steht für Buchstabenpaare
    - Korrekte Transposition ergibt guten Koinzidenzindex für Sprache
- Algorithmen: **Hill Climbing**, Simulated Annealing, Tabu Search, Genetische Algorithmen


# Weiterführendes

## Allgemein

- [Wikipedia (DE) - ADFGX](https://de.wikipedia.org/wiki/ADFGX)

- [Wikipedia (DE) - Koinzidenzindex](https://de.wikipedia.org/wiki/Koinzidenzindex)

- [Wikipedia (DE) - Morsecode](https://de.wikipedia.org/wiki/Morsezeichen)

- [Vorlesung - Grundlagen der angewandten Kryptologie (#06)](https://youtu.be/pePrEMtLMk8?t=2954) \*

- [dCode - ADFGVX CIPHER](https://www.dcode.fr/adfgvx-cipher)

<small>\* Empfehlungen</small>

## Vertiefung

- [NSA - General solution for the ADFGVX cipher system](https://www.nsa.gov/Portals/70/documents/news-features/declassified-documents/friedman-documents/publications/FOLDER_269/41784769082379.pdf)

- [NSA - Military Cryptanalysis](https://www.nsa.gov/news-features/declassified-documents/military-cryptanalysis/) \*

- [NSA - Military Cryptanalysis IV - SOLUTION OF THE ADFGVX SYSTEM](https://www.nsa.gov/Portals/70/documents/news-features/declassified-documents/military-cryptanalysis/mil_crypt_IV.pdf)

- [Deciphering ADFGVX messages from the Eastern Front of World War I](https://www.tandfonline.com/doi/abs/10.1080/01611194.2016.1169461?journalCode=ucry20) \*

<small>\* Empfehlungen</small>

## Danke für Zuhören!
