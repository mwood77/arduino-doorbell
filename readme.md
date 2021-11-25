# Arduino Doorbell
Simple project to adapt an oldschool solenoid (battery powered) doorbell to a mains powered, wireless doorbell.

## Specs
- 433 MHz receiver
- Arduino nano clone (Atmel atmega328pb)
- 5V solenoid wired to Relay NO
    - Off = HIGH
    - Ring = LOW
- Kerui KR-F53-B transmitter board
- No-name receiver board ($2 on ebay)

## Wiring Reminders
- Single 5V across all modules in parallel
- Ground across all modules in parallel
- Single breakaways for signal wiring (relay & transmitter)
- Relay closes circuit across solenoid in doorbell (wired to Normally Opened)

## Circuit Diagram
> ⚠️ I never said I was good at this


I suspect that your implementation will be different, therefore this may not be of help to you.

<img src="./circuit.svg" width="100%" height="100%" style="background-color:white">
