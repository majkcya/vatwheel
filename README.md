# vatwheel

Dieses Repository enthält ein einfaches Beispiel für die Geschwindigkeitsmessung eines Katzenrades mit einem ESP32. Die Messung erfolgt über einen Hallsensor, der an einen digitalen Pin angeschlossen wird.

Der Beispielcode befindet sich in `src/catwheel_speed.ino` und kann mit der Arduino-IDE oder PlatformIO auf einen ESP32 geladen werden.

## Aufbau

1. Befestige einen kleinen Magneten an der Innenseite des Rades.
2. Positioniere den Hallsensor so, dass er den Magneten bei jeder Umdrehung erfasst.
3. Verbinde den Sensor mit einem beliebigen GPIO des ESP32 (im Beispiel Pin 15).
4. Passe gegebenenfalls den Durchmesser des Rades im Sketch an.

Starte danach den Seriellen Monitor der IDE. Die aktuelle Geschwindigkeit wird dort im Intervall von 500 ms ausgegeben.
