namespace Container.Element;

public class User
{
    public string Name { get; set; }

    public string Login { get; set; }

    public string Password { get; set; }
    
    public override bool Equals(object obj) => this.Equals(obj as User);

    public bool Equals(User? user)
    {
        if (user is null)
            return false;
        if (object.ReferenceEquals(this, user))
            return true;
        
        if (this.GetType() != user.GetType())
        {
            return false;
        }

        return user.Name == this.Name
               && user.Login == this.Login
               && user.Password == this.Password;
    }
}