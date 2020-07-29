using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class Poot2 : MonoBehaviour
{
    private Transform transform;

    private Rigidbody2D _rigidbody2D;
    private SpriteRenderer _spriteRenderer;

    // Start is called before the first frame update
    private void Awake()
    {
        _spriteRenderer = GetComponent<SpriteRenderer>();
        _rigidbody2D = GetComponent<Rigidbody2D>();
        transform = GetComponent<Transform>();
    }

    private void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.CompareTag("Ground"))
        {
            StartCoroutine("MovePosition", transform);
        }
    }
    IEnumerator MovePosition(Transform transform)
    {
        yield return new WaitForSeconds(3f);
        _spriteRenderer.color = new Color(255, 255, 255, 0);
        
        _rigidbody2D.velocity = new Vector2(0,0);
        
        transform.position = new Vector3(Random.Range(-20, 21), 20, 0);
        _rigidbody2D.gravityScale = 0;
        yield return new WaitForSeconds(Random.Range(0f, 2f));
        
        _rigidbody2D.gravityScale = 1;
        _spriteRenderer.color = new Color(255, 255, 255, 255);
    }
}