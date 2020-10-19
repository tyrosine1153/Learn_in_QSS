using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UIElements;
public class Player : MonoBehaviour
{
    private Rigidbody2D rigidbody2D;
    private bool canJump = false;
    
    void Awake()
    {
        rigidbody2D = GetComponent<Rigidbody2D>();
    }
    
    void Update()
    {
        if (Input.GetKey(KeyCode.W) && canJump)
        {
            rigidbody2D.AddForce(new Vector2(0,500));
            canJump = false;
        }
        
        if (Input.GetKeyUp(KeyCode.S))
        {
            rigidbody2D.AddForce(new Vector2(0,-10));
        }
        
        if (Input.GetKey(KeyCode.A))
        {
            rigidbody2D.AddForce(new Vector2(-10,0));
        }
        
        if (Input.GetKey(KeyCode.D))
        {
            rigidbody2D.AddForce(new Vector2(10,0));
        }
    }

    public void OnCollisionEnter2D(Collision2D col)
    {
        if (col.gameObject.CompareTag("Star1"))
        {
            SceneManager.LoadScene("Stage2");
        }
        else if (col.gameObject.CompareTag("Star2"))
        {
            SceneManager.LoadScene("Stage3");
        }
        
        if (col.gameObject.CompareTag("Ground") || col.gameObject.CompareTag("Unground"))
        {
            canJump = true;
        }
    }

    public void OnTriggerEnter2D(Collider2D col)
    {
        if (col.gameObject.CompareTag("Poot"))
        {
            SceneManager.LoadScene("Stage1");
        }
    }
}
