[RU](Readme_rus.md) EN

# SouceHome

My implementation of smarthome protocol.

## Installation

Just clone the repository

```bash
git clone github.com/homayk228/SouceHome-Protocol/
```
Open receiver and master with Arduino IDE

Flash to master or slaves

## Protocol description

My protocol didnt have any encryption, so use at your risk!

Protocol are half-duplex, and all communication starts by master, in minimum 1 step:

Master[message_do_smf]==>slave

slave do smf and send OK back to master

Slave[mess_OK]==>master

### Commands

From 0x00 to 0xff:

0x00 - master ping slave

Pings slave to check it online or not.

0x01 - opens door

Do that it named.

0x02 slave answer

Slave's answer to master ping.

0x03 OK

Confirms that master command executed correctly by sending a answer.

0x04 read

Not implemented. Reads from sensors or data block and send data to master. What to read and send are selected by master.

0x05 load

Not implemented. Load data from master to some place in memory.

0x06 data

Not implemented.Flags data blocks in message.

From 0x07 to 0xff not used by now.

## Adressing on bus:

One master and 254 slaves(from 0x01 to 0xff).

## Editing protocol
All commands in protocol are writed in Settings block at start of code.


## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

## License

[GPL-3.0]
