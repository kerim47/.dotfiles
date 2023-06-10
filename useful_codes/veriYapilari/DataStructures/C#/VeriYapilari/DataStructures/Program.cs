using DataStructures.LinkedList.SinglyLinkedList;
using System.Collections;
using System.Threading.Channels;



LinkedList<int> liste_1 = new LinkedList<int>();
LinkedListNode<int> liste_2 = new LinkedListNode<int>(10);
liste_1.AddLast(1);
liste_1.AddLast(2);
liste_1.AddLast(3);

liste_1.AddLast(liste_2);


print(liste_1);

//var arr = new char[] { 'a', 'b', 'c' ,'a', 'd', 'e' , 'a'};
//var list = new List<char>(arr);
//var linked_list = new SinglyLinkedList<char>(list);

//linked_list.Remove('a');
//print(linked_list);


#region functions


void print<T>(IEnumerable<T> list, string sep = " ")
{
    Console.WriteLine(string.Join(sep, list));
}



static void SinglyLinkedListApp002()
{
    var arr = new char[] { 'a', 'b', 'c' };
    var arr_list = new ArrayList(arr);
    var list = new List<char>(arr);
    var c_linked_list = new LinkedList<char>(arr);

    var linked_list = new SinglyLinkedList<char>(list);
    var new_linkedlist = new SinglyLinkedList<char>(linked_list);
    foreach (var item in linked_list)
    {
        Console.Write(item + " ");
    }
}

static void SinglyLinkedListApp001()
{
    var liste_1 = new LinkedList<int>();
    var liste_2 = new LinkedList<int>();
    liste_1.AddLast(1);
    liste_1.AddLast(2);
    liste_1.AddLast(3);
    liste_1.AddLast(4);
    liste_1.AddLast(5);

    liste_2.AddLast(6);
    liste_2.AddLast(7);
    liste_2.AddLast(8);
    liste_2.AddLast(9);
    liste_2.AddLast(10);

    foreach (var item in liste_1)
    {
        Console.WriteLine(item);
    }
    // linked_list_2.AddAfter(linked_list_2.Head.Next, 32);
    //// 1 30 2 32 3

    // linked_list_2.AddBefore(linked_list_2.Head.Next, 30);
    //// 1 30  2 32 3


    // linked_list_1.AddAfter(linked_list_2.Head.Next, linked_list_1.Head);
}

static void SinglyLinkedListApp003()
{
    /// * Language Integrated Query - (LINQ)
    /// Linq ifadeleri ertelenmis ifadeleri icerir bundan dolayi 
    /// ToList kullanimina ihtiyac duyar

    var rnd = new Random();
    var initial = Enumerable.Range(1, 10).OrderBy(x => rnd.Next()).ToList();
    var linked_list = new SinglyLinkedList<int>(initial);

    var q = from item in linked_list
            where item % 2 == 1
            select item;

    //foreach (var item in q)
    //{
    //    Console.WriteLine(item);
    //}

    //linked_list.Where(x => x > 5).ToList().ForEach(x =>
    // Console.Write(x + " "));
}

void SinglyLinkedListApp005()
{
    var rnd = new Random();
    var initial = Enumerable.Range(1, 10).OrderBy(x => rnd.Next()).ToList();
    var list = new SinglyLinkedList<int>(initial);

    print(list);
    list.RemoveFirst();
    list.RemoveFirst();
    list.RemoveFirst();
    list.RemoveFirst();
    print(list);
}

void SinglyLinkedListApp006(SinglyLinkedList<char> linked_list)
{
    //linked_list.RemoveFirst();
    //linked_list.RemoveFirst();

    linked_list.RemoveLast();

    foreach (var item in linked_list)
    {
        Console.WriteLine(item);
    }
}

#endregion
