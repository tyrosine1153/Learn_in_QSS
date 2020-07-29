```c#
if (col.gameObject.CompareTag("Ground")||col.gameObject.CompareTag("Unground"))
//그라운드테그가붙은거랑비교
{
    canJump = true;
}
```

```  c#
transform = GetComponent<Transform>(); //반환자료형=메서드<원하는 컴퍼넌트 이름>
```

```c#
// Start is called before the first frame update
//시작하자마자 실행되는 메소드
void Start()
```

```c#
// Update is called once per frame
//매 프레임마다 자동으로실행되는 메소드
void Update()
```

*이거 두개(star, poot)를 태그 하나로 합칠 방법이 있을까?->상속

rlgidbody2D: 중력을 적용하는 컴포넌트

OnCollisionEnter2D : 2개의 충돌체의 isTrigger가 꺼져 있으면 호출=>물리적 접촉시,
OnTriggerEnter2D : 2개중 하나의 충돌체의 isTrigger가 켜져 있으면 호출 =>물리적 접촉이 아닌 통과될때

```c#
void OnTriggerEnter2D(Collider2D coll)//함수의 매개변수 타입이 다르다
void OnCollisionEnter2D(Collision2D coll)
```

collider의 줄임말로 위에 함수에서 매개변수로 쓰는거-> coll/col

```c#
if (Input.GetKey(KeyCode.W) && canJump) //Getkey:메서드,입력받으면 1반환
```

```c#
StartCoroutine("MovePosition", transform);//코루틴
...
IEnumerator MovePosition(Transform transform)
    {
        GetComponent<SpriteRenderer>().color = new Color(255,255,255,0);
        /*같은 오브젝트에 있는 SptriteRenderer 클래스 객체(변수)를 받아오고,
        그 안에서 Color 클래스 객체를 받은 후 해당 값을 RGB값을 흰색으로 맞추고(255,255,255), 
        alpha 값을 0으로 바꿔줌으로서 완전 투명하게 만들어준다.*/
        transform.position = new Vector3(Random.Range(-20,21),20,0);
        GetComponent<Rigidbody2D>().gravityScale = 0;
        /*같은 오브젝트에 있는 Rigidbody2D 클래스 객체를 받아오고,
         그 안에 있는 gravityScale이라는 중력 크기를 조정하는 변수를 0으로 만듦.
         따라서 공중에 뜬 채로 떨어지지 않게 됨.*/
        yield return new WaitForSeconds(Random.Range(0f,1f));
        // 0에서 1초 사이의 랜덤한 값을 가져와서 기다림.
        GetComponent<Rigidbody2D>().gravityScale = 1;
        // 중력 크기를 1로 바꿔서 다시 떨어지게 만듦.
        GetComponent<SpriteRenderer>().color = new Color(255,255,255,255);
        /* 다시 오브젝트의 스프라이트의 색깔을 흰aa색, alpha값을 255로 맞춤으로 불투명 상태로 만들어
        다시 보이게 한다.*/
        
    } //족금 기다리고 똥을 떨어뜨림
```

```c#
GetComponent<Transform>().position = new Vector3(Random.Range(-20,21),20,0);
이런건 

private Transform transform
transform = GetComponent<Transform>();
...
transform.position = new Vector3(Random.Range(-20,21),20,0);
로 줄이는게 더 활용성있다
```

```c#
class A{
	public static bool flag { get; private set; }
}
class B{
    Poot1.flag = false;//이거 안됨. 볼수는 있는데 설정은 안됨
}
```

유니티 생명주기 : 사용자가 호출하지 않아도 호출되는 함수의 호출주기. 호출시기를 사용자가 정할 수 없음

```
-Reset : 오브젝트를 생성 후 인스펙터 뷰에서 리셋을 눌러줄 때 실행됩니다. 객체의 속성을 초기 값으로 설정해 줄 때 사용합니다.

-Awake : 스크립트가 실행될 때 한번만 호출됩니다. 모든 오브젝트가 초기화 된 후 호출되기 때문에 GameObject.Find 같은 명령문을 안전하게 사용할 수 있습니다. Awake 함수는 언제나 Start 함수 전에 호출되므로 초기화 순서를 정할 수 있게 합니다. (Coroutine 사용 불가)

-OnEnable : 인스펙터뷰에서 체크를 통해서 게임 오브젝트를 활성화 할 때 사용됩니다. 활성화 할 때마다 호출 됩니다.

-Start : Update 함수가 호출되기 전에 한번만 호출됩니다. 다른 스크립트의 모든 Awake가 모두 실행된 이후에 실행됩니다. 스크립트가 활성화 되어 있어야합니다.

-FixedUpdate : 주로 물리 엔진을 사용하는 경우 일정 시간 간격으로 힘을 가할 때 사용하는 함수입니다. 발생 주기가 일정합니다. (Default : 0.02초)

-Update : 프레임마다 호출되는 함수로 게임의 핵심 로직에 사용됩니다. 스크립트가 활성화 되있어야 사용 가능하고, 주기가 일정하지 않습니다.

-LateUpdate : 모든 Update 함수가 실행되고 나서 호출됩니다. 주로 카메라 이동 로직에 사용합니다.

-OnDisable : 게임 오브젝트 또는 스크립트가 비 활성화 되었을 때 호출됩니다. (Coroutine 사용 불가)

-OnDestroy : 오브젝트 생존기간의 마지막 프레임이 업데이트 된 후 실행됩니다. (Object.Destroy 또는 씬 종료 시)

-OnApplicationQuit : 응용프로그램 종료 전에 모든 오브젝트에서 호출됩니다. 에디터에서는 플레이 모드를 중지하면 나타납니다.
출처: https://itmining.tistory.com/47 [IT 마이닝]
```

```c#
public class Asdf : MonoBehaviour
에서 'MonoBehaviour'의 경우
private Transform transform;
transform = GetComponent<Transform>();
을 생략 할 수 있다
```

