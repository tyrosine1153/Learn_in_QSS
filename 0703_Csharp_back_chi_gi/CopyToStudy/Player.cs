using System;

namespace CopyToStudy
{
    public class Player : Entity
    {
        public int mp, def;

        public Player(int hp, int mp, int atk, int def, string name, int x = 0, int y = 0) : base(hp, atk, name, x, y)
        {
            this.mp = mp;
            this.def = def;
        }

        public void Heal(int point)
        {
            this.mp -= point;
            this.hp += (point)/2 ;
            Console.WriteLine("마나를 "+point+" 사용하여 체력 "+point/2+" 회복 현재 체력 "+this.hp);
        }
    }
}