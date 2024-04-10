# State diagram

This document details the state machine implemented in this project, first with a description of each of the states, then with a state diagram. 

Note the distinction between the **INIT** initialization state and the **START** state. From an embedded software perspective, these may sound similar. However, from a musician's perspective, **INIT** is simply the default start-up condition of the transport controller, whereas **START** is a return to the start / beginning of the track.

## State descriptions

**INIT:** this is the initialization state. On power-on reset, the microcontroller is in the INIT state.
<strong style="color:purple">START:</strong>  this state entails a return to the beginning of the track.
<strong style="color:purple">REWIND:</strong> this is the resulting state after stepping back in the track by one bar.
<strong style="color:purple">FASTFORWARD:</strong> this is the resulting state after stepping forward in the track by one bar.
<strong style="color:green">PLAY:</strong> the track is actively playing.
<strong style="color:orange">STOP:</strong> the track is stopped.
<strong style="color:red">RECORD:</strong> the track is recording.


## Diagram

```mermaid
stateDiagram-v2
    classDef init fill:white,font-weight:bold
    classDef start fill:indigo,color:white,font-weight:bold
    classDef rewind fill:indigo,color:white,font-weight:bold
    classDef fastforward fill:indigo,color:white,font-weight:bold
    classDef play fill:green,color:white,font-weight:bold
    classDef stop fill:orange,color:white,font-weight:bold
    classDef record fill:red,color:white,font-weight:bold

    [*] --> INIT
    STOP --> START : Switch 1 (long)
    STOP --> REWIND : Switch 1 (short)
    STOP --> FASTFORWARD : Switch 2
    STOP --> PLAY : Switch 3
    STOP --> RECORD : Switch 4

    PLAY --> STOP : Switch 3
    PLAY --> RECORD : Switch 4

    RECORD --> STOP: Switch 3

    START --> FASTFORWARD : Switch 2
    START --> PLAY : Switch 3
    START --> RECORD : Switch 4

    INIT --> START : Switch 1 (long)
    INIT --> REWIND : Switch 1 (short)
    INIT --> FASTFORWARD : Switch 2
    INIT --> PLAY : Switch 3
    INIT --> RECORD : Switch 4
    
    REWIND --> START : Switch 1 (long)
    REWIND --> FASTFORWARD : Switch 2
    REWIND --> PLAY : Switch 3
    REWIND --> RECORD : Switch 4

    FASTFORWARD --> REWIND : Switch 1 (short)
    FASTFORWARD --> START : Switch 1 (long)
    FASTFORWARD --> PLAY : Switch 3
    FASTFORWARD --> RECORD : Switch 4

    class INIT init
    class START start
    class REWIND rewind
    class FASTFORWARD fastforward
    class PLAY play
    class STOP stop
    class RECORD record
```