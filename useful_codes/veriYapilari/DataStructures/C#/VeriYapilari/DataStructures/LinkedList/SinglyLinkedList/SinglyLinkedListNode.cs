using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
 * Bu Class yapisi bir dugumu ifade etmektedir.
 * Her dugum ifadesi tanimlandiginda bu yapi kullanilmalidir.
 */

namespace DataStructures.LinkedList.SinglyLinkedList
{
    public class SinglyLinkedListNode<T>
    {
        // Bir sonraki dugumu isaret etmektedir.
        public SinglyLinkedListNode<T> Next{ get; set; }
        // Dugumun degerini tutmaktadir.
        public T Value { get; set; }
        // Kullanici tarafindan girilen degeri Value degiskenine atama
        // islemi yapilmaktadir.
        public SinglyLinkedListNode(T value)
        {
            Value = value;
        }

        // Object nesnesinde turetilen ToString metoduu ezilerek
        // istenilen sekilde kullanilmistir.
        public override string ToString() => $"{Value}";
    }
}
