## Projektidee

Bei dem Projekt handelt es sich um eine grafische Umsetzung von TicTacToe.  
Zwei Spieler setzen abwechselnd ihre Zeichen auf ein 3x3-Spielfeld. Nach jedem Zug wird überprüft, ob eine Gewinnbedingung erfüllt wurde oder ob das Spiel unentschieden endet.

Der Fokus lag dabei auf einer sauberen, überschaubaren Struktur und einer vollständigen Umsetzung.

## Verwendete Technologien

- C++17
- SFML 3.0.2
- CMake

## Funktionen

- grafische Darstellung eines 3x3-Spielfelds
- zwei Spieler spielen abwechselnd X und O
- Erkennung von Sieg und Unentschieden
- Anzeige des aktuellen Spielstands bzw. Gewinners
- Zurücksetzen des Spiels per Tastendruck
- 
## Projektaufbau

Das Projekt ist in mehrere Dateien aufgeteilt:

- **main.cpp**  
  Enthält den Programmeinstieg, das Erstellen des Fensters, die Event-Verarbeitung und die grafische Darstellung.

- **Board.h/Board.cpp**  
  Enthält die Spielfeldlogik, also das Setzen von Feldern, die Prüfung auf freie Felder und die Ermittlung eines Gewinners.

- **Game.h/Game.cpp**  
  Verwaltet den aktuellen Spielzustand, den Spielerwechsel und das Zurücksetzen des Spiels.

## Steuerung

- **Linksklick**: Feld auswählen und Spielzug setzen
- **R**: Spiel zurücksetzen
- **ESC** oder Fenster schließen: Programm beenden

## Kompilieren und Ausführen

### Voraussetzungen

- ein C++-Compiler mit C++17-Unterstützung
- CMake
- Internetverbindung beim ersten Build, da SFML über `FetchContent` geladen wird