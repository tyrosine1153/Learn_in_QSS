using System.Security.Cryptography.X509Certificates;

namespace CopyToStudy
{
    public class Enemy : Entity
    {
        public Enemy(int hp, int atk, string name, int x = 0, int y = 0) : base(hp, atk, name, x, y) { }
    }
}