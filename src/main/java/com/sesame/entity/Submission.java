package com.sesame.entity;

import jakarta.persistence.*;
import lombok.Data;
import java.time.LocalDateTime;

@Data
@Entity
@Table(name = "submission")
public class Submission {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer id;

    private Integer userId;

    private Integer problemId;

    @Column(columnDefinition = "TEXT")
    private String code;

    private String language;

    private String result;

    private LocalDateTime submitTime;
}
