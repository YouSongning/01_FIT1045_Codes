def input_grades():
    grades = []

    size = int(input("How many grades (1 - 20): "))

    while size < 1 or size > 20:
        print("Please enter between 1 and 20.")
        size = int(input("How many grades (1 - 20): "))

    for i in range(size):
        grade = int(input(f"Enter grade {i + 1}: "))
        grades.append(grade)

    return grades


def calculate_average(grades):
    total = 0

    for grade in grades:
        total += grade

    return total / len(grades)


def calculate_pass_rate(grades):
    pass_count = 0

    for grade in grades:
        if grade >= 50:
            pass_count += 1

    return (pass_count / len(grades)) * 100


def count_hd(grades):
    hd_count = 0

    for grade in grades:
        if grade >= 80:
            hd_count += 1

    return hd_count


def display_results(average, pass_rate, hd_count):
    print("\nResults")
    print(f"Average Grade: {average:.2f}")
    print(f"Pass Rate: {pass_rate:.2f}%")
    print(f"HD Count: {hd_count}")


def main():
    grades = input_grades()

    average = calculate_average(grades)
    pass_rate = calculate_pass_rate(grades)
    hd_count = count_hd(grades)

    display_results(average, pass_rate, hd_count)

if __name__ == "__main__":
    main()