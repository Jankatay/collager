CC= gcc 
LIBSTB= stb/stb_image.o stb/stb_image_resize2.o stb/stb_image_write.o
CFLAGS= -Wall -Wextra -Werror
LFLAGS= -lm
DFLAGS= -DSTB_IMAGE_IMPLEMENTATION -DSTB_IMAGE_RESIZE_IMPLEMENTATION -DSTB_IMAGE_WRITE_IMPLEMENTATION

main: main.c append.c base.c $(LIBSTB)
	$(CC) $(CFLAGS) -o $@ $< $(LIBSTB) $(LFLAGS)


stb/%.o: stb/%.c
	$(CC) -c $(CFLAGS) $(LFLAGS) -o $@ $< $(DFLAGS) -Wno-unused-const-variable

stb/%.c: stb/%.h
	cp $< $@


.PHONY: clean
clean:
	rm -f main stb/*.o
