(defn __nwd [liczba1, liczba2]
  (if (zero? liczba2)
    liczba1
    (recur liczba2 (mod liczba1 liczba2))))


(defn skroc [liczba1 liczba2]
  (def nwd (__nwd liczba1 liczba2))
  (def pop_liczba1 liczba1)
  (def liczba1 (/ liczba1 nwd))
  (def liczba2 (/ liczba2 nwd))
  (def nwd (__nwd pop_liczba1 liczba2))
  (def liczba2 (/ liczba2 nwd))
  (print liczba1 liczba2 "\n"))

(defn main []
  (def il_zapytan (Integer/parseInt (read-line)))
  (dotimes [i il_zapytan]
    (def liczby (map #(Integer/parseInt %) (clojure.string/split (read-line) #" ")))
    (def liczba1 (nth liczby 0))
    (def liczba2 (nth liczby 1))
    (skroc liczba1 liczba2)))


(main)