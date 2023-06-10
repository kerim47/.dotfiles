using System.Collections;

namespace DataStructures.LinkedList.SinglyLinkedList
{
    internal class SinglyLinkedListEnumerator<T> : IEnumerator<T>
    {
        /// <summary>
        /// Girilcek olan dugumun basini tutar.
        /// </summary>
        private SinglyLinkedListNode<T> Head;

        /// <summary>
        /// iterasyona girilecek olan degiskeni belirtir.
        /// </summary>
        private SinglyLinkedListNode<T> _current;

        /// <summary>
        /// Ctor basslangic degerlerinin ayarlanmasi
        /// </summary>
        /// <param name="head"></param>
        public SinglyLinkedListEnumerator(SinglyLinkedListNode<T> head)
        {
            Head = head;
            _current = null;
        }

        /// <summary>
        /// Su anda bulunan dugumun degerini ifade eder.
        /// </summary>
        public T Current => _current.Value;

        /// <summary>
        /// Object turunden degeri yazilir.
        /// </summary>
        object IEnumerator.Current => Current;

        /// <summary>
        /// Erisim engellemek icin head degeri null degeri atanir.
        /// </summary>
        public void Dispose()
        {
            Head = null;
        }

        /// <summary>
        /// Bir sonraki dugumu gecer.
        /// </summary>
        /// <returns></returns>
        public bool MoveNext()
        {
            
            if (_current == null)
            {
                _current = Head;
                return true;
            }
            else
            {
                _current = _current.Next;
                return _current != null ? true : false;
            }
        }

        /// <summary>
        /// Suandaki degeri null degeri atanir.
        /// </summary>
        public void Reset()
        {
            _current = null;
        }
    }
}