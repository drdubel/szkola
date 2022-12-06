(defn main []
  (def liczby (sort (map #(Integer/parseInt %) (clojure.string/split (read-line) #" "))))
  (println (- (nth liczby (- (count liczby) 1)) (nth liczby 0))))

(main)