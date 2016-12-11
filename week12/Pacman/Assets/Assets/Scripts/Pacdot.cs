using UnityEngine;
using System.Collections;

public class Pacdot : MonoBehaviour {

    // Use this for initialization
    void Start()
    {

    }

    void OnTriggerEnter2D(Collider2D other)
    {
        if (other.name == "pacman")
        {
            //GameObject[] pacdots = GameObject.FindGameObjectsWithTag("Pacdot");
            Destroy(gameObject);
        }
    }
}
