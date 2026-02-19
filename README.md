# OpenDispenser

An Arduino-based controller for a 12V water dispenser with three solenoid valves, toggled on/off via a membrane button array.

<img src="./Circuit/OpenDispenserScheme_bb.svg">

## Bill of materials

- 1x Arduino Uno
- 3x 12V Solenoid Valve
- 3x NPN Transistor (e.g. TIP120)
- 3x 1N400x Diode (e.g. 1N4001, for back-EMF protection)
- 6x 1K Ohm Resistor
- 1x Membrane button array

## Pin mapping

| Valve | Button pin (input) | Valve pin (output) |
|---|---|---|
| 0 | 13 | 4 |
| 1 | 12 | 3 |
| 2 | 11 | 2 |

## How it works

1. Each button press toggles the corresponding valve on or off
2. The `DoubleStateButton` class handles debouncing by detecting rising-edge transitions
3. The `Valve` class manages valve state with an inhibition mechanism to prevent rapid re-triggering
4. The output pin drives the NPN transistor base, which switches the 12V solenoid valve

## Project structure

```
OpenDispenser/
├── OpenDispenser.ino        # Main sketch (3 valves, 10ms loop)
├── Valve.h/cpp              # Valve control with toggle and inhibition logic
├── DoubleStateButton.h/cpp  # Debounced button input handler
└── Circuit/
    ├── OpenDispenserScheme.fzz      # Fritzing project
    └── OpenDispenserScheme_bb.svg   # Breadboard diagram
```

## License

Apache License 2.0 - see [LICENSE](LICENSE) for details.
