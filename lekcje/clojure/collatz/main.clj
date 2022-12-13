(defn main []
  (def liczba_pocz (Integer/parseInt (read-line)))
  (while (> liczba_pocz 1)
    (if (= (mod liczba_pocz 2) 0)
      (def liczba_pocz (/ liczba_pocz 2)) (def liczba_pocz (+ (* liczba_pocz 3) 1)))
    (print liczba_pocz "")))

(main)