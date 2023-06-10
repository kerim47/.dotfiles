using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

// Tek bagli listede kullanilan methodlar kullanilmistir.

namespace DataStructures.LinkedList.SinglyLinkedList
{
    public class SinglyLinkedList<T> : IEnumerable<T>
    {
        public SinglyLinkedList(IEnumerable<T> collection)
        {
            foreach (var item in collection)
                this.AddLast(item);
        }
        public SinglyLinkedList() { }

        /// <summary>
        // SinglyLinkedListNode sinifindan turetilerek dugumun basini
        // ifade etmektedir
        /// </summary>
        public SinglyLinkedListNode<T> Head { get; set; }

        /// <summary>
        // head isaretcisinin null olup olmadigi sorgulanir
        /// </summary>
        private bool IsHeadNull => Head == null;

        /// <summary>
        // Kullanici tarafindan girilen verileri kullanilarak
        // yeni bir dugum olusturulur ve bu dugumun bir sonraki
        // isaretcisi head yapisi olarak atanarak ifade edilen yeni
        // Dugum head isaretcisine atanarak yeni dugumu ifade eder.
        // Boylece olusturulan yeni dugum hep basa eklenir.
        /// </summary>
        // <param name="value">Eklenecek değer</param>
        public void AddFirst(T value)
        {
            var new_node = new SinglyLinkedListNode<T>(value);
            new_node.Next = Head;
            Head = new_node;
        }

        /// <summary>
        // Kullanici tarafindan girilen verileri kullanilarak
        // yeni bir dugum olusturulur ve bu dugumun bir sonraki
        // isaretcisi head yapisi olarak atanarak ifade edilen yeni
        // Dugum head isaretcisine atanarak yeni dugumu ifade eder.
        // Boylece olusturulan yeni dugum hep basa eklenir.
        /// </summary>
        // <param name="value">Eklenecek değer</param>
        public void AddFirst(SinglyLinkedListNode<T> newNode)
        {
            if (newNode is null)
                throw new ArgumentNullException();
            newNode.Next = Head;
            Head = newNode;
        }

        /// <summary>
        // SinglyLinkedList yapısına ait AddLast metodu,
        // belirtilen değeri listenin sonuna ekler.
        // Eğer liste boş ise, yeni düğümü listenin başı olarak atar.
        // Değer, listenin mevcut son düğümünün hemen arkasına eklenir.
        // <param name="value">Eklenecek değer</param>
        /// </summary>
        public void AddLast(T value)
        {
            var new_node = new SinglyLinkedListNode<T>(value);
            if (IsHeadNull)
            {
                Head = new_node;
                return;
            }
            var current = Head;
            while (current.Next != null)
            {
                current = current.Next;
            }
            current.Next = new_node;
        }


        /// <summary>
        // SinglyLinkedList yapısına ait AddLast metodu,
        // belirtilen değeri listenin sonuna ekler.
        // Eğer liste boş ise, yeni düğümü listenin başı olarak atar.
        // Değer, listenin mevcut son düğümünün hemen arkasına eklenir.
        // <param name="value">Eklenecek değer</param>
        /// </summary>
        public void AddLast(SinglyLinkedListNode<T> newNode)
        {
            if(newNode == null)
            {
                throw new ArgumentNullException();
            }
            if (IsHeadNull)
            {
                Head = newNode;
                return;
            }
            var current = Head;
            while (current.Next != null)
            {
                current = current.Next;
            }
            current.Next = newNode;
        }

        /// <summary>
        /// Referans degerden sonra eleman ekleme islemi yapilmaktadir.
        /// Iki arguman alir birincisi sonraki isaretcisine eklenecek
        /// olan referans dugum ikincisi yeni dugume deger ekleme
        /// Eger referans dugum bos ise hata firlatir.
        /// yok ise veya bulunamıyorsa argumant hatasi firlatacaktir.
        /// </summary>
        /// <param name="Node"></param>
        /// <param name="Value"></param>
        /// <exception cref="ArgumentException"></exception>
        public void AddAfter(SinglyLinkedListNode<T> Node, T Value)
        {
            if (Node == null)
            {
                throw new ArgumentNullException();
            }
            if (IsHeadNull)
            {
                AddFirst(Value);
                return;
            }
            var new_node = new SinglyLinkedListNode<T>(Value);
            var iter = Head;
            while(iter != null)
            {
                if (iter.Equals(Node))
                {
                    new_node.Next = iter.Next;
                    iter.Next = new_node;
                    return;
                }
                iter = iter.Next;
            }
            throw new ArgumentException("The reference node is not in this list.");
        }

        /// <summary>
        /// Referans degerden sonra yeni bir dugum ekleme islemi yapilmaktadir.
        /// Iki arguman alir birincisi sonraki isaretcisine eklenecek
        /// olan referans dugum ikincisi yeni dugume deger ekleme
        /// Eger referans dugum bos ise hata firlatir.
        /// yok ise veya bulunamıyorsa argumant hatasi firlatacaktir.
        /// </summary>
        /// <param name="RefNode"></param>
        /// <param name="newNode"></param>
        /// <exception cref="ArgumentNullException"></exception>
        /// <exception cref="ArgumentException"></exception>
        public void AddAfter(SinglyLinkedListNode<T> RefNode, SinglyLinkedListNode<T> newNode)
        {

            if (RefNode == null || newNode == null)
            {
                throw new ArgumentNullException();
            }
            if (IsHeadNull)
            {
                Head = newNode;
                return;
            }
            var iter = Head;
            while (iter != null)
            {
                if (iter.Equals(RefNode))
                {
                    newNode.Next = iter.Next;
                    iter.Next = newNode;
                    return;
                }
                iter = iter.Next;
            }
            throw new ArgumentException("The reference node is not in this list.");
        }

        /// <summary>
        /// AddAfter fonksiyonu ile ayni islemleri yapmaktadir. Sadece bir sonraki
        /// isaretcinin girilen dugume esit olup olmadigi sorgulanir
        /// </summary>
        /// <param name="node"></param>
        /// <param name="Value"></param>
        /// <exception cref="ArgumentNullException"></exception>
        /// <exception cref="ArgumentException"></exception>
        public void AddBefore(SinglyLinkedListNode<T> Node, T Value)
        {
            if(Node == null)
                throw new ArgumentNullException();
            if (IsHeadNull)
            {
                AddFirst(Value); return;
            }

            var iter = Head;
            var new_node = new SinglyLinkedListNode<T>(Value);

            while (iter != null)
            {
                if((iter.Next).Equals(Node))
                {
                    new_node.Next = iter.Next;
                    iter.Next = new_node;
                    return;
                }
                iter = iter.Next;
            }
            throw new ArgumentException("The reference node is not in this list.");
        }

        /// <summary>
        /// Tum dugumleri tek tek gezme imkani saglar.
        /// </summary>
        /// <returns></returns>
        public IEnumerator<T> GetEnumerator()
        {
            return new SinglyLinkedListEnumerator<T>(Head);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }

        /// <summary>
        /// Ilk dugumden itibare siler.
        /// </summary>
        /// <returns>T value</returns>
        /// <exception cref="Exception"></exception>
        public T RemoveFirst()
        {
            if (IsHeadNull)
                throw new Exception("UnderFlow! nothing to remove.");
            var first_value = Head.Value;
            Head = Head.Next;
            return first_value;
        }

        /// <summary>
        /// Son dugumden itibare siler.
        /// </summary>
        /// <returns>T value</returns>
        /// <exception cref="Exception"></exception>
        public T RemoveLast()
        {
            var iter = Head;
            SinglyLinkedListNode<T> current = null;

            if (IsHeadNull)
                throw new Exception("UnderFlow! nothing to remove.");

            while (iter.Next != null)
            {
                current = iter;
                iter = iter.Next;
            }
            var last_value = current.Next.Value;
            current.Next = null;
            return last_value;
        }

        /// <summary>
        /// Bagli listede degeri olan dugumu siler.
        /// </summary>
        /// <param name="Value"></param>
        /// <exception cref="ArgumentNullException"></exception>
        /// <exception cref="ArgumentException"></exception>
        public void Remove(T Value)
        {
            if (IsHeadNull)
                throw new ArgumentNullException();
            if (Value is null)
                throw new ArgumentNullException();
            var current = Head;
            SinglyLinkedListNode<T> prev = null;

            do
            {
                if(current.Value.Equals(Value))
                {
                    if (current.Next == null)
                    {
                        if (prev == null)
                        {
                            Head = null;
                        }
                        else
                        {
                            prev.Next = null;
                            return;
                        }
                    }
                    else
                    {
                        if (prev == null)
                        {
                            Head = Head.Next;
                            return;
                        }
                        else
                        {
                            prev.Next = current.Next;
                            return;
                        }
                    }
                }
                prev = current.Next;
                current = current.Next;

            } while (current != null);

            throw new ArgumentException("The value can not be found in the list.");
        }
    }
}
