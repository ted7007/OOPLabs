using System.Collections;
using System.Reflection.Metadata;
using Container.Element;

namespace Container.Container;

public class UserCollection : ICloneable, ICollection<User>
{
    #region static

    
    public static void Swap(ref UserCollection firstCollection, ref UserCollection secondCollection) //todo нужен ли ref?
    {
        var save = firstCollection.Clone() as UserCollection ?? throw new NullReferenceException();
        firstCollection.Clear();
        firstCollection.Move(ref secondCollection);
        secondCollection.Clear();
        secondCollection = save;
        
    }
    
    public static bool operator ==(UserCollection firstCollection, UserCollection secondcollection)
    {
        return firstCollection.Equals(secondcollection);
    }
    
    public static bool operator !=(UserCollection firstCollection, UserCollection secondcollection)
    {
        return !firstCollection.Equals(secondcollection);
    }

    #endregion
    
    #region fields

    private List<User> users;
    
    #endregion

    #region properties
    
    public bool IsEmpty => users.Count == 0;

    public int Capacity => users.Capacity;



    public int Count => users.Count;

    public bool IsReadOnly => false;

    public bool IsSynchronized => false;

    public object SyncRoot => this;
    
    #endregion
    
    public UserCollection()
    {
        users = new List<User>();
    }
    
    public bool Remove(User item)
    {
        return users.Remove(item);
    }
    
    public void Add(User user)
    {
        users.Add(user);
    }

    public void AddRange(IEnumerable<User> users)
    {
        this.users.AddRange(users);
    }
    
    public override bool Equals(object obj) => this.Equals(obj as UserCollection);         
    
    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }

    public IEnumerator<User> GetEnumerator()
    {
        return users.GetEnumerator();
    }

    public object Clone()
    {
        var cloneCollection = new UserCollection();
        cloneCollection.users = new List<User>(this.users);
        return cloneCollection;
    }

    public void Move(ref UserCollection sourceCollection)  //todo нужен ли ref?
    {
        this.users.AddRange(sourceCollection.users);
        sourceCollection.users.Clear();
    }

    public void Swap(ref UserCollection collectionToSwap) //todo нужен ли ref?
    {
        var save = this.Clone() as UserCollection ?? throw new NullReferenceException();
        this.Clear();
        this.Move(ref collectionToSwap);
        collectionToSwap.Clear();
        collectionToSwap = save;
    }
    public void Clear()
    {
        users.Clear();
    }

    public bool Contains(User item)
    {
        return users.Contains(item);
    }

    public bool Equals(UserCollection? otherCollection)
    {
        if (otherCollection is null)
            return false;
        if (object.ReferenceEquals(this, otherCollection))
            return true;
        
        if (this.GetType() != otherCollection.GetType())
        {
            return false;
        }
        
        if (this.users.Count != otherCollection.users.Count)
        {
            return false;
        }

        foreach (var thisUser in users)
        {
            bool isEqualsFound = otherCollection.users.Any(otherUser => otherUser.Equals(thisUser));
            if (!isEqualsFound)
                return false;
        }

        return true;
    }
    
    public void CopyTo(User[] array, int index)
    {
        foreach (var i in users)
        {
            array.SetValue(i, index);
            index++;
        }
    }
}