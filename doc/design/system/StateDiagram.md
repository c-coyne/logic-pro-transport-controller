# State diagram

```mermaid
stateDiagram-v2
    classDef init fill:white,font-weight:bold
    classDef start fill:indigo,color:white,font-weight:bold
    classDef play fill:green,color:white,font-weight:bold
    classDef stop fill:orange,color:white,font-weight:bold
    classDef record fill:red,color:white,font-weight:bold

    [*] --> INIT
    INIT --> START : Switch 1
    INIT --> PLAY : Switch 3
    INIT --> RECORD : Switch 4
    
    RECORD --> STOP: Switch 3

    START --> PLAY : Switch 3
    START --> RECORD : Switch 4

    PLAY --> STOP : Switch 3
    PLAY --> RECORD : Switch 4

    STOP --> PLAY : Switch 3
    STOP --> START : Switch 1

    class INIT init
    class START start
    class PLAY play
    class STOP stop
    class RECORD record
```