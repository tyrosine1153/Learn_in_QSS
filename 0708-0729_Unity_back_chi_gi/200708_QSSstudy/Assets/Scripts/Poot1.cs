using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;
using UnityEngine.SceneManagement;
public class Poot1 : MonoBehaviour
{
    private Transform transform;
    void Start()
    {
        transform = GetComponent<Transform>();
    }
    void Update() { }
    private void OnCollisionEnter2D(Collision2D col)
    {
        if (col.gameObject.CompareTag("Ground"))
        {
            StartCoroutine("MovePosition", transform);
        }
    }
    IEnumerator MovePosition(Transform transform)
    {
        GetComponent<SpriteRenderer>().color = new Color(255,255,255,0);
        transform.position = new Vector3(Random.Range(-20,21),20,0);
        GetComponent<Rigidbody2D>().gravityScale = 0;
        yield return new WaitForSeconds(Random.Range(0f,1f));
        GetComponent<Rigidbody2D>().gravityScale = 1;
        GetComponent<SpriteRenderer>().color = new Color(255,255,255,255);
    }
}