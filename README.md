<p>
  <h1 align="center">GET NEXT LINE</h1>
</p>

In this project, I created a function that returns every next line of a text file each time we call it.
The prototype looks like this :

```C
char	*get_next_line(int fd)
{
	...
	return (line);
}
```
As you can see it takes a file descriptor as argument and returns a char string.
The file descriptor corresponds to the open file you wanna read from.
Here is an example of get_next_line function :

```C
int	main(void)
{
	int		fd;

	fd = open("text.txt", O_RDWR);
	/// we use printf directly to display the char string returned by get_next_line ///
	printf("Here is the first line of the file text : %s", get_next_line(fd));	
}
```
<p align="center">
	<img width="100%" alt="first_example" src="https://github.com/Vlad-PLK/GET_NEXT_LINE/assets/61476758/8012cc11-fb7e-4e0b-8b6b-14c166f16d6c">
</p>
In the picture above, you can firstly notice that we compiled with a flag "-D BUFFER_SIZE=10". BUFFER_SIZE is a variable corresponding to the number of characters read each time by read function. It means that we've made a function get_next_line that returns the first next line of a text file even if BUFFER_SIZE is a very large number or if it's equal to 1. That was a specific rule mentioned in our subject.
Right after the compilation line you can see that text.txt contains 2 lines and finally right after the cat call you see that gnl returned only the first line. 
Here's a second example with multiple lines and multiple calls of this function (obviously, I added some lines to text.txt) :

```C
int	main(void)
{
	int		fd;

	fd = open("text.txt", O_RDWR);
	printf("Here is the first line of the file text : %s", get_next_line(fd));
	printf("Here is the second line of the file text : %s", get_next_line(fd));
	printf("Here is the third line of the file text : %s", get_next_line(fd));
	printf("Here is the fourth line of the file text : %s", get_next_line(fd));
	printf("Here is the last line of the file text : %s", get_next_line(fd));
}
```
<p align="center">
	<img width="100%" alt="second_example" src="https://github.com/Vlad-PLK/GET_NEXT_LINE/assets/61476758/819a18d6-ab29-4ec5-9612-8a560dc04c33">
</p>

To make sure that our get_next_line function returns each time the very next line in a specific file we use a "static" variable that keeps track of the position in the text file after each function call.
Here's a quick explanation from [GeeksforGeeks](https://www.geeksforgeeks.org/static-variables-in-c/) to help you understand more static variables : 
<p align="center">
	<img width="50%" alt="static_variables" src="https://github.com/Vlad-PLK/GET_NEXT_LINE/assets/61476758/6ad95cb3-4884-4ec1-bc65-324c6057fc7d">
</p>
<br></br>
I'll conclude this part by talking about the benefits of such a function : 
Indeed, now that I can consistantly return the next line of a desired file, I can use it for example in a game project where GNL will help me read my map files and parse it correctly. So did I in so_long and cub3d graphic projects.
Moreover, making this function helped me understand even more how to work with strings, files, and read function. 


