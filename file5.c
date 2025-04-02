#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum Shape {
    SHAPE_CIRCLE,
    SHAPE_SQUARE,
    SHAPE_INVALID
};

enum Oper {
    OPER_FROM_LENGTH,
    OPER_FROM_AREA,
    OPER_FROM_PERIMETER,
    OPER_INVALID
};

struct Result {
    double length;
    double area;
    double perimeter;
};

enum Shape parse_shape(const char *shape) {
    if (strcmp(shape, "circle") == 0) {
        return SHAPE_CIRCLE;
    }
    if (strcmp(shape, "square") == 0) {
        return SHAPE_SQUARE;
    }
    return SHAPE_INVALID;
}

enum Oper parse_operation(const char *operation) {
    if (strcmp(operation, "length") == 0) {
        return OPER_FROM_LENGTH;
    }
    if (strcmp(operation, "area") == 0) {
        return OPER_FROM_AREA;
    }
    if (strcmp(operation, "perimeter") == 0) {
        return OPER_FROM_PERIMETER;
    }
    return OPER_INVALID;
}

void calculate(struct Result *result, enum Shape shape, enum Oper operation, double value) {
    double length, area, perimeter;

    if (shape == SHAPE_SQUARE) {
        switch(operation) {
            case OPER_FROM_LENGTH:
                length = value;
                area = length * length;
                perimeter = 4 * length;
                break;
            case OPER_FROM_AREA:
                area = value;
                length = sqrt(area);
                perimeter = 4 * length;
                break;
            case OPER_FROM_PERIMETER:
                perimeter = value;
                length = perimeter / 4;
                area = length * length;
                break;
            default:
                // Nie powinno dojść do tej sytuacji
                return;
        }
    } else if (shape == SHAPE_CIRCLE) {
        switch(operation) {
            case OPER_FROM_LENGTH:
                // length = radius
                length = value;
                area = M_PI * length * length;
                perimeter = 2 * M_PI * length;
                break;
            case OPER_FROM_AREA:
                area = value;
                length = sqrt(area / M_PI); // length = radius
                perimeter = 2 * M_PI * length;
                break;
            case OPER_FROM_PERIMETER:
                perimeter = value;
                length = perimeter / (2 * M_PI); // length = radius
                area = M_PI * length * length;
                break;
            default:
                // Nie powinno dojść do tej sytuacji
                return;
        }
    }
    result->length = length;
    result->area = area;
    result->perimeter = perimeter;
}

void print(const struct Result *result) {
    printf("Length: %.3f\n", result->length);
    printf("Area: %.3f\n", result->area);
    printf("Perimeter: %.3f\n", result->perimeter);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <shape> <input_type> <value>\n", argv[0]);
        return EXIT_FAILURE;
    }

    enum Shape shape = parse_shape(argv[1]);
    if (shape == SHAPE_INVALID) {
        fprintf(stderr, "Invalid input shape!\n");
        return EXIT_FAILURE;
    }

    enum Oper oper = parse_operation(argv[2]);
    if (oper == OPER_INVALID) {
        fprintf(stderr, "Invalid input type!\n");
        return EXIT_FAILURE;
    }

    double value = atof(argv[3]);
    if (value <= 0) {
        fprintf(stderr, "Invalid input value!\n");
        return EXIT_FAILURE;
    }

    struct Result result;
    calculate(&result, shape, oper, value);
    print(&result);

    return EXIT_SUCCESS;
}
