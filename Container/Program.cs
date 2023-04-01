// See https://aka.ms/new-console-template for more information

using Container.Container;
using Container.Element;

Console.WriteLine("Hello, World!");                     

UserCollection collection = new UserCollection();

for (int i = 0; i < 10; i++)
{
    User user = new User()
    {
        Login = "login" + i,
        Name = "Tom" + i,
        Password = "123123"
    };
    collection.Add(user);
}

foreach (var i in collection)
{
    Console.WriteLine(i.Name);
}