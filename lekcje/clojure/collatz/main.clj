(defn main []
      (loop [value (Integer/parseInt (read-line))]
            (when (> value 1)
                  (print value "")
                  (recur
                    (if (= (mod value 2) 0)
                      (/ value 2)
                      (+ (* value 3) 1)))))
      (println ""))

(main)