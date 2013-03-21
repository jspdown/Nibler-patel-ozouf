Nibler-patel-ozouf
==================

-EventEngine flash like
-multi-lib
-c++

Trame:
	wall(receive):
		-collide(receive): "collide|id|..|x:y:h:w|"


	thegame(send):
		-endofgame(send): "endofgame|id|thegame|msg|"
		-quit(send):	    "quit|id|thegame||		from graphic engine(ESC)

	snake:
		-collide(send): "collide|id|*|x:y:h:w|"
		-move left(send): "left|id|snake#0|"		from graphic engine(a|<-)
		-move right(send): "right|id|snake||"		from graphic engine(d|->)
		-eat(send): "eat|id|snake|nbr_points|"
