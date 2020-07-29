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

