(defn czy_przestepny [rok]
  (println (if (or (and (= (mod rok 100) 0) (= (mod rok 400) 0)) (and (= (mod rok 4) 0) (not= (mod rok 100) 0))) "TAK" "NIE")))

(defn main []
  (czy_przestepny (Integer/parseInt (read-line))))

(main)