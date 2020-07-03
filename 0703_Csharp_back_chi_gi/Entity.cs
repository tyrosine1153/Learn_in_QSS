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
        }

        public void Move(int x, int y)
        {
            this.x += x;
            this.y += y;
            Console.WriteLine("(" + x + " " + y + ")에 이동");
        }

        public void Attack(Entity entity)
        {
            entity.hp -= this.atk;
            Console.WriteLine(this.atk+" 의 공격력으로 "+entity.name+"을(를) 공격 "+entity.name+"의 체력이 "+entity.hp+" 남음");
        }
    }
    
}