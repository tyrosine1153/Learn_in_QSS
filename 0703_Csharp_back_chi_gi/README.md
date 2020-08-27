### 저희 오늘 뭐해용

Team.QSS 7월 3일(금) 뉴비키우기 일기

C#을 배워봅시다~ 이른바 씨샵박치기^^

선배님들이 노트북을 내지않은채로 밤새 만들었다는 실습을 해봅시다.

메인 클래스를 보고 나머지 클래스들을 예상해서 맹글어 봅시다!^^



-------------------------



### 메인코드를 살펴보자!

```c#
using System;

namespace QSS200703
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Player plr = new Player(200,100,15,0,"플레이어",0,0);
            Enemy enem = new Enemy(50,25,"해골",5,5);
            plr.Move(4,3);
            enem.Move(0, -2);
            while (enem.hp > 0 && plr.hp > 0)
            {
                plr.Attack(enem);
                enem.Attack(plr);
                plr.Heal(10);
            }
        }
    }
}
```

(이...이게모꼬...............ㅠ)

#### 객체들의 공통 구성

hp, mp, atk, def, name, x, y

##### *player만 있는 것 : mp,def



#### 객체들의 공통 행동

move-입력된 x,y만큼 위치를 바꿈
attack-공격력만큼 체력을 깎음

##### *player만 하는 것 : heal-마나를 깎아서 체력 회복



---------------------------------



### 그래서 이거 어케만드노



####  1. 객체의 특징을 묶어서 클래스로 만들자!

player와 enemy의 부모로 만들 객체(Entity)라는 클래스를 만든다. 이 클래스는 객체들의 공통적인 특징(변수, 함수)을 내용으로 가지고 있다.

##### Entity 클래스

```c#
using System;
using System.Runtime.CompilerServices;

namespace QSS200703
{
    public class Entity
    {
        public int hp, atk, x, y;
        public string name;
        public Entity(int hp, int atk, string name, int x = 0, int y = 0)
        {
            this.hp = hp;
            this.atk = atk;
            this.name = name;
            this.x = x;
            this.y = y;
        }//이것은 생성자 

        public void Move(int x, int y)
        {
            this.x += x;
            this.y += y;
            Console.WriteLine("(" + x + "," + y + ")에 이동");
        }//이것은 move함수

        public void Attack(Entity entity)
        {
            entity.hp -= this.atk;
            Console.WriteLine(this.atk+" 의 공격력으로 "+entity.name+"을(를) 공격 "+entity.name+"의 체력이 "+entity.hp+" 남음");
        }//이것은 attack함수
    }
    
}
```



#### 2. 공통된 특징을 가진 클래스를 상속한 두 클래스를 만든다!

Entity 클래스를 만들었으면 Entity클래스의 성질을 가져야 하는 Player와 Enemy 클래스를 만든다.

그리고 Entity 클래스를 상속시킨다.

Player와 Enemy 클래스에 생성자를 만드는데, 상속 받은 클래스의 변수는 가져와서 새롭게 만들 필요가 없다.

##### Entity 클래스를 상속받은 Enemy클래스

```c#
namespace QSS200703
{
    public class Enemy : Entity
    {
        public Enemy (int hp, int atk, string name, int x=0, int y=0) : base(hp,atk,name,x,y) { }
        
    }
}
```

##### Entity 클래스를 상속받은 Player클래스

```c#
using System;

namespace QSS200703
{
    public class Player : Entity
    {
        public int mp, def;//상속받은 생성자에는 mp와 def가 없으니까 여기에 또 씁니당
        public Player(int hp, int mp, int atk, int def, string name, int x = 0, int y = 0) : base(hp, atk, name, x, y)
        {
              this.mp = mp;//상속받은 생성자에는 mp와 def가 없으니까 여기에도 마찬가지
              this.def = def;
        }
          
        public void Heal(int point)//상속받은 생성자에는 대충 설명하는 말
        {
              this.mp -= point;
              this.hp += (point)/2;
              Console.WriteLine("마나 "+point+" 사용하여 체력 "+(point)/2+" 회복 현재 체력 "+this.hp);
        }
    }
}
```

