## Mandatory part - Get_next_line

<br>

| **함수 이름**                | get_next_line                                                                     |
| ---------------------------- | --------------------------------------------------------------------------------- |
| **프로토타입**               | char \*get_next_line(int fd);                                                     |
| **제출할 파일**              | get_next_line.c, get_next_line_utils.c, get_next_line.h                           |
| **매개변수**                 | 읽어들일 파일의 디스크립터 (서술자)                                               |
| **반환값**                   | 읽혀진 라인 : 한 줄이 제대로 읽힘 <br> NULL : 읽을 라인이 더이상 없거나 에러 발생 |
| **사용가능한 <br>외부 함수** | `read, malloc, free`                                                              |
| **설명**                     | 파일 디스크립터로부터 한 줄을 읽고, <br>반환하는 함수를 작성하시오.               |

<br>

## Bonus part

<br>

##### _The project `get_next_line` is straightforward and leaves very little room for bonuses, but we are sure that you have a lot of imagination. If you have aced the mandatory part, then by all means, complete this bonus part to go further. Just to be clear, no bonuses will be taken into consideration if the mandatory part isn’t perfect._

`get_next_line` 프로젝트는 간단하기 때문에 보너스를 받을 만한 여지가 거의 없지만, 우리는 여러분의 상상력이 풍부하다고 확신합니다. 만약 여러분이 필수적으로 해야하는 부분들을 완벽하게 숙달했다면, 어떻게든 보너스 파트를 완성하고 더 앞으로 나아가세요. 다시 말하지만, 필수적으로 해야하는 부분들이 완벽하지 않다면, 보너스는 고려되지 않을 것입니다.

##### _Turn-in all 3 mandatory files ending by \_bonus.[c\h] for this part._

이 파트를 위해서는 기존의 3개 파일에 \_bonus를 붙여서 제출하세요.

- ##### _To succeed `get_next_line` with a single static variable._

  하나의 정적변수로 `get_next_line` 성공하기.

- ##### _To be able to manage multiple file descriptors with your `get_next_line`. For example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call `get_next_line` once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors._
  `get_next_line`을 사용하여 여러 개의 파일 디스크립터를 관리할 수 있는 것. 예를 들어, 파일 디스크립터 3, 4, 5에 접근 가능한 경우, `get_next_line`은 각 디스크립터의 리딩 스레드를 잃지 않은 채로 3에서 한 번, 4에서 한 번, 다시 3에서 한 번, 5에서 한 번 호출될 수 있습니다.
