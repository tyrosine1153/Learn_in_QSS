using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;
using UnityEngine.SceneManagement;

public class Poot1 : MonoBehaviour
{
    private Rigidbody2D _rigidbody2D;
    private SpriteRenderer _spriteRenderer;
    
    void Awake()
    {
        _rigidbody2D = GetComponent<Rigidbody2D>();
        _spriteRenderer = GetComponent<SpriteRenderer>();
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
        _spriteRenderer.color = new Color(255,255,255,0);
        transform.position = new Vector3(Random.Range(-20,21),20,0);
        _rigidbody2D.velocity = Vector2.zero;
        
        yield return new WaitForSeconds(Random.Range(0f,1f));
        
        _spriteRenderer.color = new Color(255,255,255,255);
    }
}