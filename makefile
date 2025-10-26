CFLAGS = -g -O0 -Ivendor/sokol
LDFLAGS = -framework Cocoa -framework QuartzCore -framework Metal -framework MetalKit




default: build_third
run: run_third

clean:
	rm -r build


build_first:
	mkdir -p build
	clang -x objective-c -c src/first.c -o build/first.o $(CFLAGS)
	clang build/first.o -o build/first $(LDFLAGS)


run_first:
	./build/first

build_second:
	mkdir -p build
	clang -x objective-c -c src/second.c -o build/second.o $(CFLAGS)
	clang build/second.o -o build/second $(LDFLAGS)


run_second:
	./build/second


build_third:
	mkdir -p build
	clang -x objective-c -c src/third.c -o build/third.o $(CFLAGS)
	clang build/third.o -o build/third $(LDFLAGS)


run_third:
	./build/third
