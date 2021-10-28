이번에는 조금 재미있는 것을 해보자. 바로 터틀 그래픽스(Turtle graphics) 모듈을 이용하여 간단한 그림을 그려보는 것이다.

터틀은 어린이나 초보자들이 파이썬을 쉽게 배울 수 있도록 만든 모듈인데 거북이가 기어가는 모양대로 그림을 그린다고 하여 터틀이라고 한다.

터틀은 그림을 그리는 모듈이기 때문에 터미널(콘솔) 만 있는 환경에서는 사용할 수 없다. Windows, 리눅스, macOS 그래픽 환경에서만 동작한다.

# 1. 사각형 그리기

이제 간단하게 사각형 부터 그려보자

```python
import turtle as t

t.shape('turtle')
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8dc1f79d-4abf-4196-b944-70b1b463201c/Untitled.png)

만약 IDLE 가 아닌 Pycharm 이나 파이썬 개발 도구를 사용한다면 터틀 창이 유지되지 않고 바로 꺼질 수 있다. 그런 경우에는 코드 마지막 부분에 `t.mainloop()` 를 넣어주자.

여기에서 화면을 끄지 않은 상태에서 셸 창에 다음과 같이 입력해보자.

```python
>>> t.forward(100)
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/7393e63a-5701-4d50-a35b-bdd1a58c3b62/Untitled.png)

그러면 거북이는 100 픽셀 만큼 앞으로 이동한다.

이번에는 방향을 바꿔보자.

```python
>>> t.right(90)
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ec33f913-bacc-4af1-a550-42ad48879ffc/Untitled.png)

그러면 거북이의 방향이 오른쪽으로 90도 돌아가게 된다. 여기서 다시 다음 코드를 입력하면

```python
>>> t.forward(100)
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5514373a-36cf-4d63-a550-d4d5979b31b7/Untitled.png)

기역(ㄱ) 자 모양이 된다. 이제 지금까지 했던 것들을 활용하여 사각형을 만들어보자.

```python
>>> t.forward(100)
>>> t.right(90)
>>> t.forward(100)
>>> t.right(90)
>>> t.forward(100)
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e49e5092-8edc-4fd3-89d6-29fce404d903/Untitled.png)

이렇게 사각형을 완성했다.

## 터틀 그래픽스 명령어

- 앞으로 이동: forward, fd
- 뒤로 이동: backward, bk, back
- 왼쪽으로 회전: left, lt
- 오른쪽으로 회전: right, rt

우리가 사용했던 `forward` 나 `right` 말고도 다른 명령어들은 위와 같다. 또한 `forward` 등이 너무 길면 간단하게 `fd` 나 `rt` 를 사용해도 된다.

## 반복문 활용

그런데 앞서 사각형을 만드는게 똑같은 명령어를 여러번 넣어주는게 여간 귀찮은 작업이 아니다. 따라서 이러한 작업들을 반복문을 활용해서 만들어보자.

```python
import turtle as t

t.shape('turtle')
for i in range(4):
	t.forward(100)
	t.right(90)
t.mainloop()
```

# 2. 다각형 그리기

## 오각형 그리기

```python
import turtle as t

t.shape('turtle')
for i in range(5):
	t.forward(100)
	t.right(360/5)
t.mainloop()
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3d5e4ffc-2e7c-4157-aea3-b8526d66330f/Untitled.png)

## 입력 받은 다각형 그리기

```python
import turtle as t

t.shape('turtle')
n = int(input())
for i in range(n):
	t.forward(100)
	t.right(360/n)
t.mainloop()
```

```python
6 (입력)
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/adf88e02-14c0-4b06-9fdb-9a65d1634c4e/Untitled.png)

프로그래밍은 이런식으로 소스 코드를 일반화해 나가는 방식이다. 처음에 `for i in range(4)` 와 `t.right(90)` 을 통해서 사각형 밖에 그릴 수 없었다. 그런데 숫자 대신에 `n` 을 사용하여 사용자가 원하는 모양의 다각형을 그릴 수 있게 되었다. 이렇게 공통적인 부분을 일반화하여 원하는 결과를 얻어내는 과정이 프로그래밍이며 컴퓨테이셔널 씽킹이다.

## 다각형 색칠하기

지금까지는 기본적으로 검정색으로만 그림을 그렸다. 그렇다면 이번에는 다른 색으로 한 번 해보자

```python
import turtle as t

t.shape('turtle')
t.color('red') # 펜의 색을 빨간색으로 설정
t.begin_fill() # 색칠할 영역 시작
n = int(input())
for i in range(n):
	t.forward(100)
	t.right(360/n)
t.end_fill()
t.mainloop()   # 색칠할 영역 끝
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/bdda06c0-e63b-4b49-a043-2230fb3906f7/Untitled.png)

- `t.color('red')` : 펜의 색을 'red' 로 지정
- `t.begin_fill()` : 색칠할 영역 시작
- `t.end_fill()` :    도형에 현재 펜의 색이 칠해짐

## color 에 색깔 정하기

`color` 에 색을 지정할 때 'red', 'green', 'blue', 'yellow', 'purple', 'brown', 'gray' 등 다양한 색을 지정할 수 있다, 그러나 이름만으로는 다양한 색을 표현할 수 없다. 이럴때는 웹 색상을 이용하면 된다.

웹 색상은 #으로 시작하여 빨강(R), 초록(G), 파랑(B)에 해당하는 두 자리 16진수 세 쌍으로 구성되어 00부터 FF 까지 표현할 수 있다.

#000000: 검정

#FF0000: 빨강

#00FF00: 초록

#0000FF: 파랑

```python
t.color('#FF69B4')    # 핫핑크(hotpink)
```

# 3. 복잡한 도형 그리기

이번에는 원을 한 번 그려보겠다. 원을 그릴때는 `circle` 을 사용한다.

```python
import turtle as t

t.shape('turtle')
t.circle(120)
t.mainloop()
```

`t.circle(120)` 를 사용하여 반지름이 120 픽셀인 원을 그려보았다.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4c025e5b-1710-423d-850e-241895a48c77/Untitled.png)

## 원을 반복해서 그리기

그렇다면 `for` 을 이용해서 원을 반복적으로 그려보겠다.

```python
import turtle as t

t.shape('turtle')
t.speed('fastest')    # 그리는 속도 빠르게 설정
n = 60
for i in range(n):
	t.circle(120)
	t.right(360/n)      # 오른쪽으로 6도 회전
t.mainloop()
```

한 번 원을 그릴때 마다 6도씩 각도를 바꿔서 원을 그리면 아래와 같이 원이 겹치면서 복잡한 도형이 만들어진다.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/33c0a4ed-5fc7-4b33-95df-ab5bdc8e573f/Untitled.png)

`speed` 는 거북이의 속도를 설정한다. 속도는 숫자(0.5 부터 10까지) 나 문자열로 설정할 수 있다. 여기선 가장 빠른 `fastest` 를 사용했다.

- 'fastest': 0
- 'fast': 10
- 'normal': 6
- 'slow': 3
- 'slowest': 1

## 선으로 복잡한 무늬 그리기

```python
import turtle as t

t.shape('turtle')
t.speed('fastest')
for i in range(500):
	t.forward(i)
	t.right(91)
t.mainloop()
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/a1a8273f-7336-4c6c-a4d1-08d018ee4acd/Untitled.png)

`t.forward(i)` 로 `i` 의 값이 증가할 때 마다 점점 더 멀리 터틀이 움직이고 회전 각도를 `91` 로 설정하여 미세하게 틀어진 사각형이 만들어지면서 퍼져나가는 도형이 만들어졌다.

## % 터틀 모양 설정하기

터틀의 shape에는 'arrow', 'turtle', 'circle', 'square', 'triangle', 'classic' 등을 지정하여 여러 가지 터틀 모양을 사용할 수 있다. 특히, t.shape()와 같이 shape를 그대로 호출하면 현재 모양을 알아낼 수 있다.

```python
>>> import turtle as t
>>> t.shape('arrow')    # 화살표 모양 사용
>>> t.shape()           # 현재 모양 알아내기
'arrow'
```

## 별 그리기

```python
import turtle as t

n, line = map(int, input().split())
t.shape('turtle')
#t.speed('fastest')
for i in range(n):
	t.forward(line)
	t.right((360 / n) * 2)
	t.forward(line)
	t.left(360 / n)

t.mainloop()
```

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/45069e9b-97da-44ad-803a-bf35af1b764b/Untitled.png)
