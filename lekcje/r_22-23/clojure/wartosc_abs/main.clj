(defn main []
  #_{:clj-kondo/ignore [:inline-def]}
  (def liczba (Integer/parseInt (read-line)))
  (println (max liczba (- liczba))))

(main)
