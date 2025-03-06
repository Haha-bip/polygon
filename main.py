'''

                            Online Python Compiler.
                Code, Compile, Run and Debug python program online.
Write your code in this editor and press "Run" button to execute it.

'''

import numpy as np

def longest_sequence(arr):
    arr = np.array(arr)  # Преобразуем входные данные в массив numpy
    diff = np.diff(arr)  # Вычисляем разности между соседними элементами
    
    boundaries = (diff != 0).nonzero()[0] + 1  # Определяем границы изменений
    segment_lengths = np.diff(np.hstack(([0], boundaries, [len(arr)])))  # Вычисляем длины последовательностей
    
    return segment_lengths.max()  # Возвращаем максимальную длину

# Пример использования
arr = [1, 1, 1, 2, 2, 2, 2, 5]
print(longest_sequence(arr))  