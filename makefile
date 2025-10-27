CFLAGS = -g -O0 -Ivendor/sokol
LDFLAGS = -framework Cocoa -framework QuartzCore -framework Metal -framework MetalKit




default: build_p3-triangle
run: run_p3-triangle

clean:
	rm -r build

# ------------------------------------------------------------------------------
# p3-triangle
# ------------------------------------------------------------------------------
build_p3-triangle:
	mkdir -p build
	clang -x objective-c -c src/p3-triangle/main.c -o build/p3-triangle.o $(CFLAGS)
	clang build/p3-triangle.o -o build/p3-triangle $(LDFLAGS)


run_p3-triangle:
	./build/p3-triangle

# ------------------------------------------------------------------------------
# p2-clear
# ------------------------------------------------------------------------------
build_p2-clear:
	mkdir -p build
	clang -x objective-c -c src/p2-clear.c -o build/p2-clear.o $(CFLAGS)
	clang build/p2-clear.o -o build/p2-clear $(LDFLAGS)


run_p2-clear:
	./build/p2-clear

# ------------------------------------------------------------------------------
# p1-window
# ------------------------------------------------------------------------------
build_p1-window:
	mkdir -p build
	clang -x objective-c -c src/p1-window.c -o build/p1-window.o $(CFLAGS)
	clang build/p1-window.o -o build/p1-window $(LDFLAGS)


run_p1-window:
	./build/p1-window
