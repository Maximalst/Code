# Verschluesselung-Projekt


Spezifikation Projekt Verschlüsselung
# Klartext
Muss in einer .txt Datei abgelegt werden
Kann beliebige Länge haben, muss aber aus Zeichen der ASCII Tabelle sein!
# Schlüssel
16 Bits an Länge
Ein Text, ein Schlüssel!
Länge(Schlüssel) = Länge(Klartext)
Kann at random oder manuell vergeben werden
# Kodierung
Lesen
Blocklänge
Kann zwischen 2^6 und 2^10 Groß sein
Text aufteilen
Xor „verschlüsselung“
Text xor Schlüssel = Verschlüsselt
Schreiben
Schlüssel und Text werden in einer .txt Datei gespeichert.
Name der Datei: Name_encName_enc.txt
Die Bits werden roh in die Datei geschrieben.
Die ersten 16 Bits sind immer Schlüssel, gefolgt von 4 Bits für Blocklänge; e.g. 1001b=9d steht für eine Blocklänge von 2^9=512 Bits, der Rest ist der verschlüsselte Text. 
# Dekodierung
Lesen
Schlüssel
Blocklänge
Verschlüsselter Text
Entschlüsselung
Schreiben
Name der Datei: Name_enc.txt ->Name_dec.txt
Übertragung (API)
Interface Funktionen I/O 

# Brute-Force ist Sache der Implementation(?)
