(defn nwd [liczba1, liczba2]
  (if (zero? liczba2)
    liczba1
    (recur liczba2 (mod liczba1 liczba2))))


(defn main []
  (def il_zapytan Integer/parseIn (clojure.string/split read-line))
  (def liczby (map #(Integer/parseInt %) (clojure.string/split (read-line) #" ")))
  (def liczba1 (nth liczby 0))
  (def liczba2 (nth liczby 1))
  (println (nwd liczba1 liczba2)))


(main)