TARGET=modifydns

$(TARGET):main.c modify.h file.h
	gcc main.c modify.h file.h -o $(TARGET)
#	cp ./$(TARGET) /usr/bin/

clean:
	$(RM) a.out main *.gch