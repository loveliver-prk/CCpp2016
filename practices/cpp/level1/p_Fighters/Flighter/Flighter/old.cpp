//����
/*sf::Texture bg;
if (!bg.loadFromFile(("bg.png")))
{
	cout << "failed to open the file";
	system("pause");
	exit(0);
}

sf::Sprite myBg;
myBg.setTexture(bg);

//��������ı���

//�Լ��ķɻ�
sf::Texture plane;
if (!plane.loadFromFile(("shoot.png"), sf::IntRect(2, 100, 98, 125)))
{
	cout << "failed to open the file";
	system("pause");
	exit(0);
}
plane.setSmooth(true);

//�ɻ���ʼλ��
float leftRight = 275;

sf::Sprite myPlane;
myPlane.setTexture(plane);
myPlane.setPosition(sf::Vector2f(leftRight, 725));
myPlane.setScale(sf::Vector2f(0.5f, 0.5f));
myPlane.setColor(sf::Color(0, 200, 100, 255));

//���С  ֡��60
sf::RenderWindow window(sf::VideoMode(600, 800), "myWindow");
window.setFramerateLimit(60);

//ѭ������
while (window.isOpen())
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (event.type == sf::Event::LostFocus)
		{
			continue;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		// left key is pressed: move our character
		if (leftRight > 0)
		{
			leftRight -= 10;
			myPlane.setPosition(sf::Vector2f(leftRight, 725));
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		// left key is pressed: move our character
		if (leftRight < 550)
		{
			leftRight += 10;
			myPlane.setPosition(sf::Vector2f(leftRight, 725));
		}
	}

	//window.clear(sf::Color::White);//�װ��ɫ

	window.draw(myBg);//����

	window.draw(myPlane);//�Լ��ķɻ�

	window.display();
}

return 0;*/