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
- `vim .bashrc` kannst du nun die Datei öffnen und bearbeiten (vim ist ein Texteditor, `:q` zu schließen).
- Eine neue alias setzt du, indem du `alias <short-cut>=<befehl>` eingibst, z.B. `alias..=‘cd ..‘`, so musst du beim Wechseln in ein Verzeichnis davor nicht mehr `cd ..` sondern nur noch `..` eingeben, denk dran vor dem Schließen deine Änderung zu speichern.
- Um die Änderung zu laden musst du die bashrc nochmal einlesen mit `. .bashrc`, wäre auch durch öffnen und schließen des Terminals passiert.

Kopieren, Verschieben, Löschen:
- `cp <Quelldatei> <Zieldatei oder Zielverzeichnis>`, kopiert Quelldatei nach Zieldatei bzw. Zielverzeichnis
- `mv <Quelldatei> <Zieldatei oder Zielverzeichnis>`, verschiebt Quelldatei nach Zieldatei bzw. Zielverzeichnis
- `rm -r <Datei/Verzeichnis>`, löscht Datei/Verzeichnis, bei Verzeichnis muss -r angegeben werden

Schreiben von Dateien
- `vim`, Editor um Dateien anzusehen, oder zu erstellen (alternativ `nvim` wenn möglich)

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
- Durch die Eingabe von `ssh -Y user@server` kann von der lokalen Konsole auf den Server zugegriffen werden, unter Eingabe des Passworts.
- Von allen Servern kannst du auf das Verzeichnis `/data/` zu greifen, hier ist für jeden Benutzer ein Verzeichnis angelegt, sowie ein Gruppenverzeichnis unter `/data/Groups/agzilges`.
- Die Verschlüsselung der Daten verläuft über einen public und einen private key. Ist der public key auf dem Server hinterlegt, kann die Authentifizierung über den private key gelingen, ohne dass ein Passwort nötig wäre.
