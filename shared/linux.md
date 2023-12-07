# Basis: Linux

## Befehle
Öffnen eines Terminals mittels <kbd>Ctrl</kbd>+<kbd>Alt</kbd>+<kbd>T</kbd> oder <kbd>![Windows Key][winlogo]</kbd> + "Term"

Häufige Befehle, die in der Konsole verwendet werden:
- `cd`
	- `cd <Verzeichnis>` wechselt in ein Verzeichnis
	- `cd ..`, geht ein Verzeichnis höher
	- `cd ~`, wechselt in das Homeverzeichnis
- `pwd`, zeigt das aktuelle Verzeichnis an
- `ls`, zeigt den Inhalt eines Verzeichnisses an
- `mkdir <Verzeichnisnamen>`, erstellt ein Verzeichnis

Alias:
- Viele der oben genannten Befehle werden sehr regelmäßig verwendet, weswegen es sich lohnt sogenannte "Alias" (Abkürzungen) zu setzten.
- Dafür muss die `.bashrc` geöffnet werden, diese Datei wir bei jedem öffnen des Terminals mitgeladen. Wechsel dafür mit `cd ~` in dein Homeverzeichnis.
- `gedit .bashrc` kannst du nun die Datei öffnen und bearbeiten (gedit ist ein Texteditor).
- Eine neue alias setzt du, indem du `alias <short-cut>=<befehl>` eingibst, z.B. `alias..=‘cd ..‘`, so musst du beim Wechseln in ein Verzeichnis davor nicht mehr `cd ..` sondern nur noch `..` eingeben, denk dran vor dem Schließen deine Änderung zu speichern.
- Um die Änderung zu laden musst du die bashrc nochmal einlesen mit `. .bashrc`, wäre auch durch öffnen und schließen des Terminals passiert.

Kopieren, Verschieben, Löschen:
- `cp <Quelldatei> <Zieldatei oder Zielverzeichnis>`, kopiert Quelldatei nach Zieldatei bzw. Zielverzeichnis
- `mv <Quelldatei> <Zieldatei oder Zielverzeichnis>`, verschiebt Quelldatei nach Zieldatei bzw. Zielverzeichnis
- `rm -r <Datei/Verzeichnis>`, löscht Datei/Verzeichnis, bei Verzeichnis muss -r angegeben werden

Schreiben von Dateien
- `gedit`, Editor um Dateien anzusehen, oder zu erstellen (alternativ `vim`)

Anzeigen von Dateien:
- `cat <Datei0> … <Dateien>`, zeigt die Dateien hintereinander an
- `less <Datei>`, zweigt eine Datei an, wobei man vor und zurück gehen kann.

Länge, Kopf und Fußteil:
- `wc` Zeigt die Anzahl der Zeilen, Worte und Zeichen an
- `head -n <N> <Name>`, zeigt die letzten <N> Zeilen der Datei <Name> an
- `tail -n <N> <Name>`, zeigt die letzen <N> Zeilen der Datei <Name> an

Umleitung der Ausgabe:
- Mit dem Zeichen `>` leitet man die Ausgabe in eine Datei um. Die Datei wird überschieben: `programm > ausgabe`
- Mit dem Zeichen `>>` leitet man die Ausgabe in eine Datei um. Die Ausgabe wir an die Datei angehängt: `programm >> ausgabe`
- Mit dem Zeichen `|` leitet man die Ausgabe an ein weiteres Programm weiter (pipen): `programm1 | programm2`

Zugriffsrechte:
- `ll`, zeigt den detaillierten Inhalt eines Verzeichnisses an, wie zum Beispiel:

	```
	drwxr-xr-x. 7 ehoemann 5145 2048 Mar 16 09:28 BasicsTutorial
	```
	- der erste Buchstabe ist bei einem Verzeichnis ein d, sonst ein -, darauffolgend sind drei Blöcke mit je drei Zeichen aufgeführt, die jeweils für Besitzer(u), Gruppe(g) und andere Nutzer(o), bzw. alle(a) stehen.
	- Die Zugriffsrechte werden durch r=read, w=write, x=execute dargestellt.
- `chmod <options> <file>` bei options gibt man nun ein, für wen Rechte geändert werden sollen (u/g/o/a) mit + werden Rechte gegeben mit  entzogen, z.B. `a+rx` (jetzt darf jeder die Datei lesen und ausführen).
- `chown <user>(:<group>)` ändert den Eigentümer der Datei, bzw. die Gruppe.

Secure Shell:
- Damit große Datenmengen nicht auf dem lokalen PC bearbeitet werden müssen besitzt das IKP eine Reihe von Servern:
Gaia, Helios, Kronos, Poseidon, Thanatos.
- Durch die Eingabe von `ssh -X user@server` kann von der lokalen Konsole auf den Server zugegriffen werden, unter Eingabe des Passworts.
- Von allen Servern kannst du auf das Verzeichnis `/data/` zu greifen, hier ist für jeden Benutzer ein Verzeichnis angelegt, sowie ein Gruppenverzeichnis unter `/data/Groups/agzilges`.
- Die Verschlüsselung der Daten verläuft über einen public und einen private key. Ist der public key auf dem Server hinterlegt, kann die Authentifizierung über den private key gelingen, ohne dass ein Passwort nötig wäre.

## awk
Awk ist eine Programmiersprache zur Bearbeitung und Auswertung einfacher Textdaten, die aus
mehreren Spalten bestehen. Gegeben sei die Datei `daten.dat` mit drei Spalten

| $`x`$ | $`x^2`$ | $`x^3`$ |
| ----- | ------- | ------- |
| 1  | 1   | 1    |
| 2  | 4   | 8    |
| 3  | 9   | 27   |
| 4  | 16  | 64   |
| 5  | 25  | 125  |
| 6  | 36  | 216  |
| 7  | 49  | 343  |
| 8  | 64  | 512  |
| 9  | 81  | 729  |
| 10 | 100 | 1000 |

Mit awk ist es möglich, nur eine Spalte ausgeben zu lassen. Die zweite Spalte wird beispielsweise mit dem Befehl

    awk ´{print $2}´ daten.dat

ausgeben. Mit folgendem Befehl werden die Zeilen ausgegeben, in denen die 1. Spalte gleich vier ist:

    awk ´{if($1==4) {print $0}}´ daten.dat

Mit folgendem Befehl wird die zweite Spalte in jeder Zeile verdoppelt und zusätzlich am Anfang start und am Ende stopp ausgaben:

    awk ´BEGIN{print ´´start´´}{print $1, $2*2, $3} END{print ´´stop´´}´ daten.dat

Mit folgendem Befehl wird die Summe der dritten Spalte berechnet:

    awk ´BEGIN{sum=0} {sum = sum + $3} END {print sum}´ daten.dat

[winlogo]: https://i.stack.imgur.com/Rfuw7.png
